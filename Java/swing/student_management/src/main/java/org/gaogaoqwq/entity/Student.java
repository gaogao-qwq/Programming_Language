package org.gaogaoqwq.entity;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class Student {

    private String id;

    private String sno;

    private String name;

    private String password;

    private int chineseScore;

    private int mathScore;

}
