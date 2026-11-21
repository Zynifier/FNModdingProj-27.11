// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortActivatablePanel.generated.h"

class UObject;
class USoundBase;
class UWidget;

UENUM(BlueprintType)
enum class EInputPriority : uint8
{
	Normal = 0,
	Menu = 1,
	Chat = 2,
	Modal = 3,
	Confirmation = 4,
	Error = 5,
	HUD = 6,
};

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortActivatablePanel : public UCommonActivatablePanelLegacy, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Fort Activatable Panel|Audio", meta=(AdvancedDisplay="2", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject"))
	void AsyncPlaySound2D(const UObject* WorldContextObject, TSoftObjectPtr<USoundBase> SoundToLoad, float VolumeMultiplier = 1.000000f, float PitchMultiplier = 1.000000f, float StartTime = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Fort Activatable Panel")
	void RestoreCenterWidget(UWidget* FallbackWidget = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fort Activatable Panel")
	void RestoreScrollWidget(UWidget* FallbackWidget = nullptr);

	UPROPERTY(BlueprintReadOnly, Category="Fort Activatable Panel")
	bool bIsPushedOnToContentPanelStack;

	UPROPERTY(BlueprintReadOnly, Category="Fort Activatable Panel")
	bool bIsAlreadyOnContentPanelStack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Activatable Panel")
	EInputPriority InputPriority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Activatable Panel")
	bool bIsClosableByPlayerInput;

protected:
	UPROPERTY(EditAnywhere, Category="Fort Activatable Panel")
	FPrimaryContentSetup PrimaryContentSetup;

};

