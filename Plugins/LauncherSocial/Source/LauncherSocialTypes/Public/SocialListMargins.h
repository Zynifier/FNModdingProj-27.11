// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Math/MathFwd.h"
#include "SocialListMargins.generated.h"

USTRUCT()
struct FSocialListMargins
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D UserPresenceImageSize;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin HeaderButtonMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendsListMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendsListNoFriendsMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendsListHeaderMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendsListHeaderCountMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin HeaderButtonContentMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendItemMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendItemStatusMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendTipStatusMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendItemPresenceMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendItemPlatformMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendItemTextScrollerMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ConfirmationBorderMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ConfirmationButtonMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ConfirmationButtonContentMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin NoneFriendContentMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	float NoneFriendContentHeight;

	UPROPERTY(EditAnywhere, Category="Appearance")
	float NoneFriendIconWidth;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin SubMenuBackIconMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin SubMenuPageIconMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin RadioSettingTitleMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin SubMenuSearchIconMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin SubMenuSearchTextMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin SubMenuBackButtonMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin SubMenuSettingButtonMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin SubMenuListMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	float SubMenuSeperatorThickness;

	UPROPERTY(EditAnywhere, Category="Appearance")
	float PresenceSeperatorThickness;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendTipMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendTipPresenceMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendTipSeperatorMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ToolTipMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin TipStatusMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin AddButtonMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D AddButtonSpacing;

};

