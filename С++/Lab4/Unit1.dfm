object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 242
  ClientWidth = 329
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object LabelTranslated: TLabel
    Left = 134
    Top = 58
    Width = 42
    Height = 16
    Caption = 'PForm:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelAnswer: TLabel
    Left = 130
    Top = 107
    Width = 48
    Height = 16
    Caption = 'Answer:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelExercise: TLabel
    Left = 116
    Top = 9
    Width = 86
    Height = 16
    Caption = 'Enter exercise:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelA: TLabel
    Left = 6
    Top = 169
    Width = 13
    Height = 16
    Caption = #1040':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelB: TLabel
    Left = 68
    Top = 169
    Width = 12
    Height = 16
    Caption = 'B:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelC: TLabel
    Left = 130
    Top = 169
    Width = 13
    Height = 16
    Caption = 'C:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelD: TLabel
    Left = 193
    Top = 169
    Width = 13
    Height = 16
    Caption = 'D:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelE: TLabel
    Left = 256
    Top = 169
    Width = 12
    Height = 16
    Caption = 'E:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object EditExercise: TEdit
    Left = 8
    Top = 31
    Width = 305
    Height = 21
    TabOrder = 0
  end
  object EditTranslated: TEdit
    Left = 8
    Top = 80
    Width = 306
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 205
    Width = 89
    Height = 25
    Caption = 'Solve'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 224
    Top = 205
    Width = 89
    Height = 25
    Caption = 'Clear'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button2: TButton
    Left = 113
    Top = 205
    Width = 89
    Height = 25
    Caption = 'Quit'
    TabOrder = 4
    OnClick = Button2Click
  end
  object EditAnswer: TEdit
    Left = 7
    Top = 129
    Width = 306
    Height = 21
    TabOrder = 5
  end
  object EditA: TEdit
    Left = 25
    Top = 168
    Width = 37
    Height = 21
    TabOrder = 6
  end
  object EditB: TEdit
    Left = 86
    Top = 168
    Width = 38
    Height = 21
    TabOrder = 7
  end
  object EditC: TEdit
    Left = 149
    Top = 168
    Width = 38
    Height = 21
    TabOrder = 8
  end
  object EditD: TEdit
    Left = 212
    Top = 168
    Width = 38
    Height = 21
    TabOrder = 9
  end
  object EditE: TEdit
    Left = 274
    Top = 168
    Width = 39
    Height = 21
    TabOrder = 10
  end
end
