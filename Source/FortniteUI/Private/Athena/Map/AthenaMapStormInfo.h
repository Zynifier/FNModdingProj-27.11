// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "FortHUDElementWidget.h"
#include "AthenaMapStormInfo.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapStormInfo : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Extension Widget Created"))
	void BP_HandleExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSafeZoneCountChanged(int32 SafeZoneCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSafeZonePhaseChanged(int32 SafeZonePhase);

private:
	UPROPERTY(EditAnywhere, Category="AthenaMapStormInfo")
	FScalableFloat SafeZoneDamageAttribute;

	UPROPERTY(EditAnywhere, Category="AthenaMapStormInfo")
	FText SafeZonePhaseFormatText;

	UPROPERTY(EditAnywhere, Category="AthenaMapStormInfo")
	FText StormIncomingFormatText;

	UPROPERTY(EditAnywhere, Category="AthenaMapStormInfo")
	FText StormDamageFormatText;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0", DisplayName="Safe Zone Phase"))
	int32 DesignTime_SafeZonePhase;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Safe Zone Count"))
	int32 DesignTime_SafeZoneCount;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0", DisplayName="Storm Damage"))
	int32 DesignTime_StormDamage;
#endif

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapStormInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SafeZonePhase;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_StormDamage;

};

