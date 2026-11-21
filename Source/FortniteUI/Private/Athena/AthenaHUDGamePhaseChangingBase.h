// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "Athena/GamePhaseWidget.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "AthenaHUDGamePhaseChangingBase.generated.h"

class UActorComponent;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UImage;
class UMaterialInterface;
class UOverlay;
class USoundMix;
enum class EAthenaGamePhaseStep : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaHUDGamePhaseChangingBase : public UGamePhaseWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="Handle Game Phase Step Changed"))
	void BP_HandleGamePhaseStepChanged(const EAthenaGamePhaseStep Step);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetIsRanked(const bool bIsRanked);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetPlaylistName(const FText& PlaylistName);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetRankedProgress(const FString& ProgressKey, const int32 RankedTier, const int32 RankedPosition, const float RankedPercent);

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="Update Messaging"))
	void BP_UpdateMessaging(const EAthenaGamePhaseStep Step, const FText& NewMessage, const FText& NewTimeText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool DoesMinigamePreventUpdatesAtPhase(uint8 Value);

	UFUNCTION(BlueprintPure)
	bool GetShowRankedProgressCvar() const;

	UFUNCTION(BlueprintPure)
	bool IsGamePhaseStepNotificationWidgetVisible(const EAthenaGamePhaseStep PhaseStepType) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool IsRiftSpawning();

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	void PlayCountdownAudio(const FText& NewTimeText, const EAthenaGamePhaseStep Step) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayGamePhaseAlertSound(const EAthenaGamePhaseStep Step) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayIntroAnimation(const EAthenaGamePhaseStep Step);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ToggleCompass(bool bHide) const;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase")
	TObjectPtr<USoundMix> LaunchingSoundMix;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase")
	TMap<EAthenaGamePhaseStep, TObjectPtr<UMaterialInterface>> IconMaterials;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase")
	FText PlayersText;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase")
	FText DeployingInText;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase")
	EAthenaGamePhaseStep CurrentPhase;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase")
	FVector2D MessageTranslationTop;

	UPROPERTY(BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase")
	FVector2D MessageTranslationBottom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase", meta=(MultiLine="true"))
	FText BusStateMessageGetReady;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase", meta=(MultiLine="true"))
	FText BusStateMessageBusLocked;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AthenaHUDGamePhaseChangingBase", meta=(MultiLine="true"))
	FText BusStateMessageBusFlying;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_AlertType;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_BusIconState;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_BPVisibility;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TimeText;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Message;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BusTimer;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BusLine1;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BusLine2;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaHUDGamePhaseChangingBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Icon;

private:
	UFUNCTION(BlueprintCallable)
	UActorComponent* GetSpawnOverrideComponent();

	UFUNCTION(BlueprintCallable)
	void UpdateActiveWidgetIndex(const EAthenaGamePhaseStep Index);

};

