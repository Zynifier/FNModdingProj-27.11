// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "Styling/SlateTypes.h"
#include "SocialListStyle.generated.h"

USTRUCT()
struct FSocialListStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle GlobalChatButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush GlobalChatIcon;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle FriendItemButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle ConfirmButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle CancelButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateColor ButtonContentColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateColor ButtonHoverContentColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ActionMenuArrowBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ActionMenuArrowRightBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateColor ActionMenuBackgroundColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ToolTipArrowBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle BackButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle HeaderButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle FriendListActionButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush AddFriendButtonContentBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush StatusIconBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush PCIconBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ConsoleIconBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush MobileIconBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush FacebookIconBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush EpicIconBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush FriendImageBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush OfflineBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush OnlineBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush AwayBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush SpectateBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush FriendsContainerBackground;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush FriendsListBackground;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FEditableTextBoxStyle AddFriendEditableTextStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush BackBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush SelectedOptionBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush SettingsBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush SeperatorBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush PresenceSeperatorBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush FontSizeBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush SearchBrush;

};

