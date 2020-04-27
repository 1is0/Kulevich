object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 361
  ClientWidth = 636
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 114
    Width = 41
    Height = 23
    Caption = 'A = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 141
    Width = 41
    Height = 23
    Caption = 'B = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 48
    Top = 168
    Width = 41
    Height = 23
    Caption = 'C = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 48
    Top = 195
    Width = 42
    Height = 23
    Caption = 'D = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 48
    Top = 222
    Width = 40
    Height = 23
    Caption = 'E = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 64
    Top = 32
    Width = 153
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Text = '(a-b)/(c+d)*e'
  end
  object Memo1: TMemo
    Left = 280
    Top = 30
    Width = 337
    Height = 184
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
  end
  object Button1: TButton
    Left = 40
    Top = 280
    Width = 137
    Height = 41
    Caption = 'Apply'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 95
    Top = 114
    Width = 49
    Height = 21
    TabOrder = 3
    Text = '0.3'
  end
  object Edit3: TEdit
    Left = 95
    Top = 141
    Width = 49
    Height = 21
    TabOrder = 4
    Text = '6.7'
  end
  object Edit4: TEdit
    Left = 95
    Top = 168
    Width = 49
    Height = 21
    TabOrder = 5
    Text = '8.4'
  end
  object Edit5: TEdit
    Left = 95
    Top = 195
    Width = 49
    Height = 21
    TabOrder = 6
    Text = '9.5'
  end
  object Edit6: TEdit
    Left = 95
    Top = 222
    Width = 49
    Height = 21
    TabOrder = 7
    Text = '1.2'
  end
end
