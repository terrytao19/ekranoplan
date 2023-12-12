    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 166;
            section.data(166)  = dumData; %prealloc

                    ;% rtP.Apolar
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.CD0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.CL0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.CLDe
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.CLa
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.CLa_dot
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.CLq
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.CYDr
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.CYb
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.ClDa
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.ClDr
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Clb
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Clp
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Clr
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.Cm0
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.CmDe
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.Cma
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.Cma_dot
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.Cmq
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.CnDa
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.CnDr
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.Cnb
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.Cnp
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.Cnr
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.Euler_0
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.ISA_T0
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 27;

                    ;% rtP.ISA_g
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 28;

                    ;% rtP.ISA_hmax
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 29;

                    ;% rtP.ISA_lapse
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 30;

                    ;% rtP.ISA_rho0
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 31;

                    ;% rtP.Ixx
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 32;

                    ;% rtP.Iyy
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 33;

                    ;% rtP.Izz
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 34;

                    ;% rtP.Pos_0
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 35;

                    ;% rtP.chord
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 38;

                    ;% rtP.mass
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 39;

                    ;% rtP.span
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 40;

                    ;% rtP.DiscretePIDController4_D
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 41;

                    ;% rtP.DiscretePIDController_D
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 42;

                    ;% rtP.DiscretePIDController1_D
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 43;

                    ;% rtP.DiscretePIDController2_D
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 44;

                    ;% rtP.DiscretePIDController3_D
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 45;

                    ;% rtP.DiscretePIDController4_DifferentiatorICPrevScaledInput
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 46;

                    ;% rtP.DiscretePIDController_DifferentiatorICPrevScaledInput
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 47;

                    ;% rtP.DiscretePIDController1_DifferentiatorICPrevScaledInput
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 48;

                    ;% rtP.DiscretePIDController4_I
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 49;

                    ;% rtP.DiscretePIDController_I
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 50;

                    ;% rtP.DiscretePIDController1_I
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 51;

                    ;% rtP.DiscretePIDController2_I
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 52;

                    ;% rtP.DiscretePIDController3_I
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 53;

                    ;% rtP.DiscretePIDController2_InitialConditionForFilter
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 54;

                    ;% rtP.DiscretePIDController3_InitialConditionForFilter
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 55;

                    ;% rtP.DiscretePIDController4_InitialConditionForIntegrator
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 56;

                    ;% rtP.DiscretePIDController_InitialConditionForIntegrator
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 57;

                    ;% rtP.DiscretePIDController1_InitialConditionForIntegrator
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 58;

                    ;% rtP.DiscretePIDController2_InitialConditionForIntegrator
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 59;

                    ;% rtP.DiscretePIDController3_InitialConditionForIntegrator
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 60;

                    ;% rtP.DiscretePIDController4_LowerSaturationLimit
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 61;

                    ;% rtP.DiscretePIDController1_LowerSaturationLimit
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 62;

                    ;% rtP.DiscretePIDController3_LowerSaturationLimit
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 63;

                    ;% rtP.DiscretePIDController2_N
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 64;

                    ;% rtP.DiscretePIDController3_N
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 65;

                    ;% rtP.DiscretePIDController4_P
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 66;

                    ;% rtP.DiscretePIDController_P
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 67;

                    ;% rtP.DiscretePIDController1_P
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 68;

                    ;% rtP.DiscretePIDController2_P
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 69;

                    ;% rtP.DiscretePIDController3_P
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 70;

                    ;% rtP.DiscretePIDController4_UpperSaturationLimit
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 71;

                    ;% rtP.DiscretePIDController1_UpperSaturationLimit
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 72;

                    ;% rtP.DiscretePIDController3_UpperSaturationLimit
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 73;

                    ;% rtP.SliderGain_gain
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 74;

                    ;% rtP.SliderGain1_gain
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 75;

                    ;% rtP.SliderGain_gain_hyc34xasfz
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 76;

                    ;% rtP.SliderGain1_gain_mv1hpouzrh
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 77;

                    ;% rtP.SliderGain_gain_bsd0ykrtc0
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 78;

                    ;% rtP.WindZ_XData
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 79;

                    ;% rtP.WindZ_YData
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 3081;

                    ;% rtP.u_Gain
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 6083;

                    ;% rtP.WindY_XData
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 6084;

                    ;% rtP.WindY_YData
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 9086;

                    ;% rtP.u_Gain_lth2troxad
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 12088;

                    ;% rtP.WindX_XData
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 12089;

                    ;% rtP.WindX_YData
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 15091;

                    ;% rtP._Gain
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 18093;

                    ;% rtP.MatrixGain6_Gain
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 18094;

                    ;% rtP.ubvbwb_IC
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 18103;

                    ;% rtP.Integrator_gainval
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 18106;

                    ;% rtP.Tsamp_WtEt
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 18107;

                    ;% rtP.Integrator_gainval_gsc5ke3qa1
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 18108;

                    ;% rtP.Tsamp_WtEt_eenah0djpv
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 18109;

                    ;% rtP.Integrator_gainval_pgxpxjbdlc
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 18110;

                    ;% rtP.Tsamp_WtEt_i0xopibhwa
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 18111;

                    ;% rtP.Switch_Threshold
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 18112;

                    ;% rtP.Integrator_gainval_fn0merchw3
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 18113;

                    ;% rtP.Filter_gainval
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 18114;

                    ;% rtP.Integrator_gainval_kdbzsgvpvb
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 18115;

                    ;% rtP.Filter_gainval_elrzqrryfc
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 18116;

                    ;% rtP.u2_Gain
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 18117;

                    ;% rtP.R2D3_Gain
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 18118;

                    ;% rtP.R2D2_Gain
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 18119;

                    ;% rtP.R2D1_Gain
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 18120;

                    ;% rtP.D2R_Gain
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 18121;

                    ;% rtP.Deg2Rad_Gain
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 18122;

                    ;% rtP.Gain4_Gain
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 18123;

                    ;% rtP.Deg2Rad2_Gain
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 18124;

                    ;% rtP.Gain1_Gain
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 18125;

                    ;% rtP.pqr_IC
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 18126;

                    ;% rtP.Switch_Threshold_hwgs5rnbxi
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 18129;

                    ;% rtP.Gain_Gain
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 18130;

                    ;% rtP.Limitaltitude_LowerSat
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 18131;

                    ;% rtP.Gain_Gain_mqy02r1o31
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 18132;

                    ;% rtP.Deg2Rad1_Gain
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 18133;

                    ;% rtP.Gain1_Gain_nqisqcqfrw
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 18134;

                    ;% rtP.Gain1_Gain_ftpoywohzv
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 18135;

                    ;% rtP.Gain1_Gain_e2mkjz4tqt
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 18136;

                    ;% rtP.Gain2_Gain
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 18137;

                    ;% rtP.Gain4_Gain_ljfjkw1syf
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 18138;

                    ;% rtP.Deg2Rad3_Gain
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 18139;

                    ;% rtP.Gain3_Gain
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 18140;

                    ;% rtP.Gain3_Gain_jhgwt4xcre
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 18141;

                    ;% rtP.Gain4_Gain_fd51wengpv
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 18142;

                    ;% rtP.Gain1_Gain_dpix5mof3i
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 18143;

                    ;% rtP.Gain4_Gain_ohs20inw3v
                    section.data(123).logicalSrcIdx = 122;
                    section.data(123).dtTransOffset = 18144;

                    ;% rtP.Gain4_Gain_n3uynydxab
                    section.data(124).logicalSrcIdx = 123;
                    section.data(124).dtTransOffset = 18145;

                    ;% rtP.Gain3_Gain_gjw5qqxglj
                    section.data(125).logicalSrcIdx = 124;
                    section.data(125).dtTransOffset = 18146;

                    ;% rtP.Gain5_Gain
                    section.data(126).logicalSrcIdx = 125;
                    section.data(126).dtTransOffset = 18147;

                    ;% rtP.Throttle2RPM_Gain
                    section.data(127).logicalSrcIdx = 126;
                    section.data(127).dtTransOffset = 18148;

                    ;% rtP.mps2fps_Gain
                    section.data(128).logicalSrcIdx = 127;
                    section.data(128).dtTransOffset = 18149;

                    ;% rtP.Saturation_UpperSat
                    section.data(129).logicalSrcIdx = 128;
                    section.data(129).dtTransOffset = 18150;

                    ;% rtP.Saturation_LowerSat
                    section.data(130).logicalSrcIdx = 129;
                    section.data(130).dtTransOffset = 18151;

                    ;% rtP.lbs2kg_Gain
                    section.data(131).logicalSrcIdx = 130;
                    section.data(131).dtTransOffset = 18152;

                    ;% rtP.Saturation1_UpperSat
                    section.data(132).logicalSrcIdx = 131;
                    section.data(132).dtTransOffset = 18153;

                    ;% rtP.Saturation1_LowerSat
                    section.data(133).logicalSrcIdx = 132;
                    section.data(133).dtTransOffset = 18154;

                    ;% rtP.R2D2_Gain_jrhz3pfqfv
                    section.data(134).logicalSrcIdx = 133;
                    section.data(134).dtTransOffset = 18155;

                    ;% rtP.Gain_Gain_a1wggbqhys
                    section.data(135).logicalSrcIdx = 134;
                    section.data(135).dtTransOffset = 18156;

                    ;% rtP.Gain1_Gain_mlyplvcvro
                    section.data(136).logicalSrcIdx = 135;
                    section.data(136).dtTransOffset = 18165;

                    ;% rtP.Gain2_Gain_kp2d4nocmq
                    section.data(137).logicalSrcIdx = 136;
                    section.data(137).dtTransOffset = 18174;

                    ;% rtP.Gain3_Gain_kf22pabip4
                    section.data(138).logicalSrcIdx = 137;
                    section.data(138).dtTransOffset = 18183;

                    ;% rtP.R2D1_Gain_g0cjd2kme4
                    section.data(139).logicalSrcIdx = 138;
                    section.data(139).dtTransOffset = 18184;

                    ;% rtP.Zpositiveisdown_Gain
                    section.data(140).logicalSrcIdx = 139;
                    section.data(140).dtTransOffset = 18185;

                    ;% rtP.R2D_Gain
                    section.data(141).logicalSrcIdx = 140;
                    section.data(141).dtTransOffset = 18194;

                    ;% rtP.nowind_Value
                    section.data(142).logicalSrcIdx = 141;
                    section.data(142).dtTransOffset = 18195;

                    ;% rtP.Constant4_Value
                    section.data(143).logicalSrcIdx = 142;
                    section.data(143).dtTransOffset = 18198;

                    ;% rtP.Constant1_Value
                    section.data(144).logicalSrcIdx = 143;
                    section.data(144).dtTransOffset = 18199;

                    ;% rtP.Constant4_Value_lvvzxuwh5z
                    section.data(145).logicalSrcIdx = 144;
                    section.data(145).dtTransOffset = 18208;

                    ;% rtP.Constant_Value
                    section.data(146).logicalSrcIdx = 145;
                    section.data(146).dtTransOffset = 18209;

                    ;% rtP.Deg2Rad4_Gain
                    section.data(147).logicalSrcIdx = 146;
                    section.data(147).dtTransOffset = 18210;

                    ;% rtP.Gain2_Gain_b4uvpqpdbd
                    section.data(148).logicalSrcIdx = 147;
                    section.data(148).dtTransOffset = 18211;

                    ;% rtP.Gain1_Gain_nbhhfd3fwa
                    section.data(149).logicalSrcIdx = 148;
                    section.data(149).dtTransOffset = 18212;

                    ;% rtP.Cmq1_Value
                    section.data(150).logicalSrcIdx = 149;
                    section.data(150).dtTransOffset = 18213;

                    ;% rtP.Cmq1_Value_dqzexw0fvg
                    section.data(151).logicalSrcIdx = 150;
                    section.data(151).dtTransOffset = 18214;

                    ;% rtP.Gain1_Gain_dd3z2ich2e
                    section.data(152).logicalSrcIdx = 151;
                    section.data(152).dtTransOffset = 18215;

                    ;% rtP.Cmq1_Value_hei4fwlj0u
                    section.data(153).logicalSrcIdx = 152;
                    section.data(153).dtTransOffset = 18216;

                    ;% rtP.Cmq1_Value_acz4kovyrj
                    section.data(154).logicalSrcIdx = 153;
                    section.data(154).dtTransOffset = 18217;

                    ;% rtP.Constant_Value_cqthaabju2
                    section.data(155).logicalSrcIdx = 154;
                    section.data(155).dtTransOffset = 18218;

                    ;% rtP.Constant1_Value_g5jniqvvpl
                    section.data(156).logicalSrcIdx = 155;
                    section.data(156).dtTransOffset = 18219;

                    ;% rtP.Gain3_Gain_jo4inzsfgw
                    section.data(157).logicalSrcIdx = 156;
                    section.data(157).dtTransOffset = 18220;

                    ;% rtP.Gain3_Gain_fosanw5ymw
                    section.data(158).logicalSrcIdx = 157;
                    section.data(158).dtTransOffset = 18221;

                    ;% rtP.Weightmatrix_Value
                    section.data(159).logicalSrcIdx = 158;
                    section.data(159).dtTransOffset = 18222;

                    ;% rtP.Constant_Value_ibkcrpfjyo
                    section.data(160).logicalSrcIdx = 159;
                    section.data(160).dtTransOffset = 18225;

                    ;% rtP.Constant1_Value_a4soj351ll
                    section.data(161).logicalSrcIdx = 160;
                    section.data(161).dtTransOffset = 18231;

                    ;% rtP.Constant2_Value
                    section.data(162).logicalSrcIdx = 161;
                    section.data(162).dtTransOffset = 18252;

                    ;% rtP.Constant3_Value
                    section.data(163).logicalSrcIdx = 162;
                    section.data(163).dtTransOffset = 18253;

                    ;% rtP.Constant_Value_d3cgtfumsg
                    section.data(164).logicalSrcIdx = 163;
                    section.data(164).dtTransOffset = 18265;

                    ;% rtP.airpseed_desired_Value
                    section.data(165).logicalSrcIdx = 164;
                    section.data(165).dtTransOffset = 18266;

                    ;% rtP.h_desired_Value
                    section.data(166).logicalSrcIdx = 165;
                    section.data(166).dtTransOffset = 18267;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.ManualSwitch1_CurrentSetting
                    section.data(1).logicalSrcIdx = 166;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 65;
            section.data(65)  = dumData; %prealloc

                    ;% rtB.ewh2czgzt2
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.ffht1uab1p
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.av1jt30k31
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

                    ;% rtB.eisyorlq2r
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 9;

                    ;% rtB.m0diztvarb
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtB.ncckp5giye
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtB.m1c2gjrdhf
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% rtB.gyndz2ty42
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% rtB.jlifrmbka3
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 14;

                    ;% rtB.c2nosomft5
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% rtB.c4zgqksn3s
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% rtB.m30uwutjd5
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% rtB.amv5xbxcgx
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% rtB.ctr2i5cu0j
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% rtB.pvv2cmskei
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% rtB.gst3ni0ebl
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

                    ;% rtB.agbvtgnrv4
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% rtB.hjhp5kuoxj
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 23;

                    ;% rtB.glpu5b5wth
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 24;

                    ;% rtB.ej2atzfwl0
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 25;

                    ;% rtB.ldelskn1jo
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 28;

                    ;% rtB.ljudbp5sfm
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 31;

                    ;% rtB.mhbhj1bpzc
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 32;

                    ;% rtB.ezi3wqgg1t
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 33;

                    ;% rtB.j4csspowr5
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 34;

                    ;% rtB.es5qqkki5l
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 35;

                    ;% rtB.lda1u2jc0p
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 36;

                    ;% rtB.hxc25hdudb
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 37;

                    ;% rtB.crwpdhv3lp
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 38;

                    ;% rtB.aq2in4etwi
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 39;

                    ;% rtB.lg5hpscltc
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 40;

                    ;% rtB.h1saod1n1q
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 46;

                    ;% rtB.f4k3dw2w0v
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 47;

                    ;% rtB.m5psfntta4
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 48;

                    ;% rtB.m3gvnxject
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 49;

                    ;% rtB.l0izt2oa2m
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 50;

                    ;% rtB.jfnjrao1g3
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 51;

                    ;% rtB.fwckhvycxa
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 52;

                    ;% rtB.ddcf0ek4jw
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 55;

                    ;% rtB.cmwuafgi05
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 61;

                    ;% rtB.aoodyqcbut
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 62;

                    ;% rtB.k1afspykmn
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 65;

                    ;% rtB.lc5ruufnmk
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 68;

                    ;% rtB.ckb3sq150e
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 71;

                    ;% rtB.hrq2k5iwyr
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 72;

                    ;% rtB.knqqe5buxf
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 73;

                    ;% rtB.pxzonjrd4i
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 74;

                    ;% rtB.deddzxm4gc
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 75;

                    ;% rtB.o0ugrkeqpd
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 76;

                    ;% rtB.ijvi5t5r0z
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 112;

                    ;% rtB.i5zbjzuhhx
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 113;

                    ;% rtB.kwxg3amuly
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 114;

                    ;% rtB.b1n2m12ywt
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 115;

                    ;% rtB.bx1plzk1jh
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 116;

                    ;% rtB.eej5dfdnuw
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 117;

                    ;% rtB.leydlmjwwh
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 118;

                    ;% rtB.exx2dadn0g
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 119;

                    ;% rtB.ebpprftokq
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 120;

                    ;% rtB.b152zcpgbp
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 121;

                    ;% rtB.l0yxgnvu5h
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 122;

                    ;% rtB.lokluenstr
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 123;

                    ;% rtB.heursz1pm4
                    section.data(62).logicalSrcIdx = 62;
                    section.data(62).dtTransOffset = 124;

                    ;% rtB.irq1dwevjt
                    section.data(63).logicalSrcIdx = 65;
                    section.data(63).dtTransOffset = 125;

                    ;% rtB.lbgz1x4wje
                    section.data(64).logicalSrcIdx = 66;
                    section.data(64).dtTransOffset = 127;

                    ;% rtB.jhen0kkdwf
                    section.data(65).logicalSrcIdx = 67;
                    section.data(65).dtTransOffset = 128;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 9;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.kjy5vllogw
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.blkvfyc1ut
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dbof0j1l1z
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.epsgdxius2
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.i5vdoafna1
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.f21v3dtx13
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.odzrzx3nyk
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ko2emyti4i
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.hx53qo0tyb
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.hoflvlpyvq
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.bsuso3aou5
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.kqs40q3ion
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 30;
            section.data(30)  = dumData; %prealloc

                    ;% rtDW.ot01cjf44p.LoggedData
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ienxpx13ox.LoggedData
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lonsi5tvy2.LoggedData
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.bopkytftsp.LoggedData
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.mukxshufya.LoggedData
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.i2ymfnvraf.LoggedData
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.fpsvbqvcgs.LoggedData
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.cl0ejounxl.LoggedData
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.ac4mtsmytw.LoggedData
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.jswy3gs4if.LoggedData
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.m5knzhq5rr.LoggedData
                    section.data(11).logicalSrcIdx = 22;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.a0xwp4frij.LoggedData
                    section.data(12).logicalSrcIdx = 23;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.o11ub12fkb.LoggedData
                    section.data(13).logicalSrcIdx = 24;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.lpwv0ihuhs.LoggedData
                    section.data(14).logicalSrcIdx = 25;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.bo3mponwcp.LoggedData
                    section.data(15).logicalSrcIdx = 26;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.mtyb0k5fng.LoggedData
                    section.data(16).logicalSrcIdx = 27;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.g4ynicugn1.LoggedData
                    section.data(17).logicalSrcIdx = 28;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.glbmpk0lvf.LoggedData
                    section.data(18).logicalSrcIdx = 29;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.kmvfsayspc.LoggedData
                    section.data(19).logicalSrcIdx = 30;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.pxgw4feuo1.LoggedData
                    section.data(20).logicalSrcIdx = 31;
                    section.data(20).dtTransOffset = 19;

                    ;% rtDW.gaotct0bee.LoggedData
                    section.data(21).logicalSrcIdx = 32;
                    section.data(21).dtTransOffset = 20;

                    ;% rtDW.iql4ez3dau.LoggedData
                    section.data(22).logicalSrcIdx = 33;
                    section.data(22).dtTransOffset = 21;

                    ;% rtDW.atwrl0cbxb.FilePtr
                    section.data(23).logicalSrcIdx = 34;
                    section.data(23).dtTransOffset = 22;

                    ;% rtDW.bdydrqopie.LoggedData
                    section.data(24).logicalSrcIdx = 35;
                    section.data(24).dtTransOffset = 23;

                    ;% rtDW.k4za1xg10g.LoggedData
                    section.data(25).logicalSrcIdx = 36;
                    section.data(25).dtTransOffset = 24;

                    ;% rtDW.gibulb434z.LoggedData
                    section.data(26).logicalSrcIdx = 37;
                    section.data(26).dtTransOffset = 25;

                    ;% rtDW.f0qoodbnbc.AQHandles
                    section.data(27).logicalSrcIdx = 38;
                    section.data(27).dtTransOffset = 26;

                    ;% rtDW.mk3ro0stcv.AQHandles
                    section.data(28).logicalSrcIdx = 39;
                    section.data(28).dtTransOffset = 27;

                    ;% rtDW.dyyoqexn4d.AQHandles
                    section.data(29).logicalSrcIdx = 40;
                    section.data(29).dtTransOffset = 28;

                    ;% rtDW.oo3juhdx4t.LoggedData
                    section.data(30).logicalSrcIdx = 41;
                    section.data(30).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.hbijqpjfmj
                    section.data(1).logicalSrcIdx = 42;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.gg3skupl10
                    section.data(2).logicalSrcIdx = 43;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.no3jro0ul3
                    section.data(3).logicalSrcIdx = 44;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.mcybje2ozl
                    section.data(4).logicalSrcIdx = 45;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.no2vyppbyo.Count
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.n33rcmsjab
                    section.data(2).logicalSrcIdx = 47;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.jye5a0flet
                    section.data(3).logicalSrcIdx = 48;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.ejk4nu5buq
                    section.data(4).logicalSrcIdx = 49;
                    section.data(4).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.mhy0u4hbsx
                    section.data(1).logicalSrcIdx = 50;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ljddttc2rd
                    section.data(2).logicalSrcIdx = 51;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.iddriykzwh
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ouacim1lgo
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.buclet5t4e
                    section.data(3).logicalSrcIdx = 54;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.pxpfngwwzn
                    section.data(4).logicalSrcIdx = 55;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.mqsusrzct3
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.gzmh1uauzr
                    section.data(2).logicalSrcIdx = 57;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.a0cdktfgmq
                    section.data(3).logicalSrcIdx = 58;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.jzqwpkv30d
                    section.data(4).logicalSrcIdx = 59;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.kksiycbt0b
                    section.data(5).logicalSrcIdx = 60;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.jhvamlflm5
                    section.data(6).logicalSrcIdx = 61;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.gzval4tfha
                    section.data(7).logicalSrcIdx = 62;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.l2krxsgpd1
                    section.data(8).logicalSrcIdx = 63;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 4191752109;
    targMap.checksum1 = 3512113050;
    targMap.checksum2 = 4255664101;
    targMap.checksum3 = 1875852696;

