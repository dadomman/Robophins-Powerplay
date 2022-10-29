package org.firstinspires.ftc.teamcode;

import com.qualcomm.robotcore.eventloop.opmode.LinearOpMode;
import com.qualcomm.robotcore.eventloop.opmode.TeleOp;
import com.qualcomm.robotcore.hardware.DcMotor;
import com.qualcomm.robotcore.hardware.DcMotorSimple;
import com.qualcomm.robotcore.hardware.HardwareMap;
import com.qualcomm.robotcore.hardware.Servo;

import java.util.Map;

public class Ppbot{
    public DcMotor BLeft = null;
    public DcMotor BRight = null;
    public DcMotor FLeft = null;
    public DcMotor FRight = null;
    public DcMotor Slider = null;
    public Servo Take = null;

    HardwareMap map = null;
    public void init(HardwareMap maps) {
        map = maps;
        BLeft = maps.dcMotor.get("bl");
        BRight = maps.dcMotor.get("br");
        FLeft = maps.dcMotor.get("fl");
        FRight = maps.dcMotor.get("fr");
        Take = maps.servo.get("take");
        Slider = maps.dcMotor.get("s");

        BLeft.setDirection(DcMotorSimple.Direction.REVERSE);
        BRight.setDirection(DcMotorSimple.Direction.FORWARD);
        FLeft.setDirection(DcMotorSimple.Direction.REVERSE);
        FRight.setDirection(DcMotorSimple.Direction.FORWARD);
        Slider.setDirection(DcMotorSimple.Direction.FORWARD);

        BLeft.setPower(0.0);
        BRight.setPower(0.0);
        FLeft.setPower(0.0);
        FRight.setPower(0.0);
        Slider.setPower(0.0);

        BLeft.setMode(DcMotor.RunMode.RUN_WITHOUT_ENCODER);
        BRight.setMode(DcMotor.RunMode.RUN_WITHOUT_ENCODER);
        FLeft.setMode(DcMotor.RunMode.RUN_WITHOUT_ENCODER);
        FRight.setMode(DcMotor.RunMode.RUN_WITHOUT_ENCODER);
        Slider.setMode(DcMotor.RunMode.RUN_USING_ENCODER);

    }
}

@TeleOp (name = "PowerPlaybot", group = "pp")

public class Pp extends LinearOpMode{
    Ppbot robot = new Ppbot();
    double x;
    double y;
    double rx;
    double Armpos = 0.0;
    double Slidepos = 0.0;
    final double Armspeed = 0.1;
    final double Slidespeed = 0.5;

    @Override

    public void runOpMode(){
        robot.init(hardwareMap);
        telemetry.addData("Say", "Hello");
        telemetry.update();

        waitForStart();

        while(opModeIsActive()){
            y = -gamepad1.left_stick_y;
            x = gamepad1.left_stick_x;
            rx = gamepad1.right_stick_x;

            double x2 = x*Math.cos(-Math.PI/4) - y*Math.sin(-Math.PI/4);
            double y2 = y*Math.cos(-Math.PI/4) + x*Math.sin(-Math.PI/4);

            if (Math.abs(rx) > 0){
                robot.BLeft.setPower(-rx);
                robot.BRight.setPower(-rx);
                robot.FLeft.setPower(rx);
                robot.FRight.setPower(rx);
            }
            else {
                robot.BLeft.setPower(y2);
                robot.BRight.setPower(y2);
                robot.FLeft.setPower(x2);
                robot.FRight.setPower(x2);

            }

            telemetry.addData("x","%.2f", x);
            telemetry.addData("y","%.2f", y);
            telemetry.update();

            sleep(50);

        }
    }

}