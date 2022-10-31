n = eval(input())
match n:
    case n if n < 35:
        print("空气优质，建议户外活动！")
    case n if 35 <= n < 75:
        print("空气良好，适度户外活动！")
    case n if n >= 75:
        print("空气污染，请小心！")
