#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct QueueFamilyIndices {
	uint32_t graphicsFamily;
	uint32_t presentFamily;
} QueueFamilyIndices;
static bool isComplete(QueueFamilyIndices *indices) {
	printf("%u, %u\n", indices->presentFamily, indices->graphicsFamily);
	return indices->graphicsFamily != UINT32_MAX && indices->presentFamily != UINT32_MAX;
}

static VkResult res;
static GLFWwindow *window;
static VkInstance instance;
static VkSurfaceKHR surface;
static VkPhysicalDevice physicalDevice;
static VkDevice logicalDevice;
static VkQueue graphicsQueue;
static VkQueue presentQueue;
static QueueFamilyIndices queueFamilyIndices;
static VkDeviceQueueCreateInfo *queueCreateInfos;

static VkApplicationInfo appInfo = {
	.sType				= VK_STRUCTURE_TYPE_APPLICATION_INFO,
	.pNext				= NULL,
	.pApplicationName	= "Hello World",
	.applicationVersion	= VK_MAKE_VERSION(0, 0, 1),
	.pEngineName		= "No Engine",
	.engineVersion		= VK_MAKE_VERSION(0, 0, 1),
	.apiVersion			= VK_API_VERSION_1_3
};

static VkInstanceCreateInfo instanceCreateInfo = {
	.sType						= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	.pNext						= NULL,
	.flags						= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR,
	.pApplicationInfo			= &appInfo,
	.enabledLayerCount			= 0,
	.ppEnabledLayerNames		= NULL,
	.enabledExtensionCount		= 0,
	.ppEnabledExtensionNames	= NULL
};

static VkPhysicalDeviceFeatures deviceFeatures = { VK_FALSE };

static VkDeviceCreateInfo deviceCreateInfo = {
	.sType						= VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
	.pNext						= NULL,
	.flags						= 0U,
	.queueCreateInfoCount		= 0,
	.pQueueCreateInfos			= NULL,
	.enabledLayerCount			= 0,
	.ppEnabledLayerNames		= NULL,
	.enabledExtensionCount		= 0,
	.ppEnabledExtensionNames	= NULL,
	.pEnabledFeatures			= &deviceFeatures,
};

static const char* deviceExtensions[] = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME,
};
static uint32_t deviceExtensionsCount = 1;

static void checkSupport();
static void getRequiredExtensions();
static void createInstance();
static bool isDeviceSuitable(VkPhysicalDevice device);
static bool checkDeviceExtensionSupport(VkPhysicalDevice device);
static void pickPhysicalDevice();
static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
static void createLogicalDevice();
static void createSwapChain();
static void createWindow();
static void createWindowSurface();
static void initVulkan();
static void destroyVulkan();
static void destroyWindow();
static void cleanup();
static void mainLoop();

int main(void) {
	checkSupport();
	initVulkan();
	mainLoop();
	return 0;
}

static void checkSupport() {
	if (!glfwInit()) {
		printf("Failed to Initialize glfw\n");
		exit(EXIT_FAILURE);
	}
	if (!glfwVulkanSupported()) {
		printf("Vulkan not support\n");
		exit(EXIT_FAILURE);
	}
}

static void getRequiredExtensions() {
	uint32_t glfwExtensionCount = 0;
	const char **glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	printf("%d vulkan extensions found: ", glfwExtensionCount);
	for (uint32_t i = 0; i < glfwExtensionCount; ++i) {
		printf("%s", glfwExtensions[i]);
		if (i != glfwExtensionCount - 1) printf(", ");
	}
	printf("\n");
	instanceCreateInfo.enabledExtensionCount = glfwExtensionCount;
	instanceCreateInfo.ppEnabledExtensionNames = glfwExtensions;
}

static void createInstance() {
	res = vkCreateInstance(&instanceCreateInfo, NULL, &instance);
	if (res != VK_SUCCESS) {
		printf("[%d]: Instance creation failed\n", res);
		cleanup();
		exit(EXIT_FAILURE);
	}
}

static bool isDeviceSuitable(VkPhysicalDevice device) {
	queueFamilyIndices = findQueueFamilies(device);
	bool extensionsSupported = checkDeviceExtensionSupport(device);
	return isComplete(&queueFamilyIndices) && extensionsSupported;
	// VkPhysicalDeviceProperties deviceProperties;
    // VkPhysicalDeviceFeatures deviceFeatures;
	// vkGetPhysicalDeviceProperties(device, &deviceProperties);
	// vkGetPhysicalDeviceFeatures(device, &deviceFeatures);
	// return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
	// 	deviceFeatures.geometryShader;
}

static bool checkDeviceExtensionSupport (VkPhysicalDevice device) {
	uint32_t extensionCount;
	vkEnumerateDeviceExtensionProperties(device, NULL, &extensionCount, NULL);
	VkExtensionProperties *availableExtensions = malloc(extensionCount * sizeof(VkExtensionProperties));
	vkEnumerateDeviceExtensionProperties(device, NULL, &extensionCount, availableExtensions);

	return true;
}

static void pickPhysicalDevice() {
	uint32_t deviceCount = 0;
	res = vkEnumeratePhysicalDevices(instance, &deviceCount, NULL);
	if (deviceCount == 0) {
		printf("Failed to find GPUs with Vulkan support!\n");
		cleanup();
		exit(EXIT_FAILURE);
	}
	printf("%d devices found:\n", deviceCount);

	VkPhysicalDevice *devices = malloc(deviceCount * sizeof(VkPhysicalDevice));
	res = vkEnumeratePhysicalDevices(instance, &deviceCount, devices);
	if (res != VK_SUCCESS) {
		printf("[%d]: Enumerate physical devices failed\n", res);
		cleanup();
		exit(EXIT_FAILURE);
	}

	VkPhysicalDeviceProperties deviceProperties;
	for (uint32_t i = 0; i < deviceCount; ++i) {
		vkGetPhysicalDeviceProperties(devices[i], &deviceProperties);
		printf("[Device %d]: %s", i, deviceProperties.deviceName);
		if (!isDeviceSuitable(devices[i])) {
			printf("(Not suitable)\n");
			continue;
		}
		printf("\n");
		physicalDevice = devices[i];
	}
	if (!physicalDevice) {
		printf("Cannot find suitable physical device\n");
		exit(EXIT_FAILURE);
	}
}

static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) {
	QueueFamilyIndices indices = { .graphicsFamily = UINT32_MAX, .presentFamily = UINT32_MAX };
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, NULL);
	if (!queueFamilyCount)
		return indices;

	VkBool32 presentSupport = false;
	VkQueueFamilyProperties *queueFamilies = malloc(queueFamilyCount * sizeof(VkQueueFamilyProperties));
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies);
	for (uint32_t i = 0; i < queueFamilyCount && !isComplete(&indices); ++i) {
		if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT && indices.graphicsFamily == UINT32_MAX) {
			indices.graphicsFamily = i;
		}
		vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);
		if (presentSupport && indices.presentFamily == UINT32_MAX) {
			indices.presentFamily = i;
		}
	}
	return indices;
}

static void createLogicalDevice() {
	res = vkCreateDevice(physicalDevice, &deviceCreateInfo, NULL, &logicalDevice);
	if (res != VK_SUCCESS) {
		printf("[%d]: Failed to create logical device!\n", res);
		cleanup();
		exit(EXIT_FAILURE);
	}

	uint32_t queueFamilyCount =
		queueFamilyIndices.graphicsFamily == queueFamilyIndices.presentFamily ? 1 : 2;
	uint32_t *uniqueQueueFamiliies = malloc(queueFamilyCount * sizeof(uint32_t));
	VkDeviceQueueCreateInfo *queueCreateInfos = 
		malloc(queueFamilyCount * sizeof(VkDeviceQueueCreateInfo));

	printf("Create logical device successfully\n");
	printf("Using %d unique queue family to create device queue\n", queueFamilyCount);

	float queuePriority = 1.0f;
	for (uint32_t i = 0; i < queueFamilyCount; ++i) {
		VkDeviceQueueCreateInfo queueCreateInfo = {
			.sType				= VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
			.pNext				= NULL,
			.flags				= VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT,
			.queueFamilyIndex	= uniqueQueueFamiliies[i],
			.queueCount			= 1,
			.pQueuePriorities	= &queuePriority
		};
		queueCreateInfos[i] = queueCreateInfo;
	}

	deviceCreateInfo.queueCreateInfoCount = queueFamilyCount;
	deviceCreateInfo.pQueueCreateInfos = queueCreateInfos;

	vkGetDeviceQueue(logicalDevice, queueFamilyIndices.graphicsFamily, 0, &graphicsQueue);
	vkGetDeviceQueue(logicalDevice, queueFamilyIndices.presentFamily, 0, &presentQueue);
}

static void createSwapChain() {
	
}

static void createWindow() {
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
	if (!window) {
		cleanup();
		exit(EXIT_FAILURE);
	}
}

static void createWindowSurface() {
	res = glfwCreateWindowSurface(instance, window, NULL, &surface);
	if (res != VK_SUCCESS) {
		printf("[%d]: Surface creation failed\n", res);
		cleanup();
		exit(EXIT_FAILURE);
	}
}

static void initVulkan() {
	getRequiredExtensions();
	createInstance();
	createWindow();
	createWindowSurface();
	pickPhysicalDevice();
	createLogicalDevice();
}

static void destroyVulkan() {
	vkDestroySurfaceKHR(instance, surface, NULL);
	vkDestroyInstance(instance, NULL);
	vkDestroyDevice(logicalDevice, NULL);
}

static void destroyWindow() {
	glfwDestroyWindow(window);
	glfwSetWindowShouldClose(window, 1);
	glfwTerminate();
}

static void cleanup() {
	destroyVulkan();
	destroyWindow();
}

static void mainLoop() {
	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
	vkDeviceWaitIdle(logicalDevice);
}

