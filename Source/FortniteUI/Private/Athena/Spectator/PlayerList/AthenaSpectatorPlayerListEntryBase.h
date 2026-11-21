// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Spectator/EventMatchInfo/AthenaSpectatorPlayerWidgetBase.h"
#include "AthenaSpectatorPlayerListEntryBase.generated.h"

class UAthenaSpectatorHitPointBarBase;
class UCommonBorder;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UImage;

UCLASS(Abstract)
class UAthenaSpectatorPlayerListEntryBase : public UAthenaSpectatorPlayerWidgetBase
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Show Squad ID"))
	bool bDesignTime_ShowSquadId;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Show Event Score"))
	bool bDesignTime_ShowEventScore;
#endif

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_SquadColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SquadId;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_KillScore;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorHitPointBarBase> HitPoint_HealthBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorHitPointBarBase> HitPoint_ShieldBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EventScore;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RecordingPlayerIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_FollowedPlayerIcon;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button;

};

