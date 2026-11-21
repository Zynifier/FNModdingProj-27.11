// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBangInterface.h"
#include "FortTypes.h"
#include "FortBangWrapper_NUI.generated.h"

class UNamedSlot;
class UObject;
class USoundBase;
enum class EFortBangType : uint8;
enum class ETutorialType : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortBangWrapper_NUI : public UCommonUserWidget, public IFortBangInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="BangWrapper|Audio", meta=(AdvancedDisplay="2", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject"))
	FORTNITEUI_API void AsyncPlaySound2D(const UObject* WorldContextObject, TSoftObjectPtr<USoundBase> SoundToLoad, float VolumeMultiplier = 1.000000f, float PitchMultiplier = 1.000000f, float StartTime = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="BangWrapper", meta=(DisplayName="Set Bang State"))
	FORTNITEUI_API void SetBangStateBP(bool bEnabled, int32 Count);

	UFUNCTION(BlueprintCallable, Category="BangWrapper")
	FORTNITEUI_API void SetBangType(EFortBangType NewBangType);

	UFUNCTION(BlueprintCallable, Category="BangWrapper")
	FORTNITEUI_API void SetTutorialNameID(FName InTutorialNameID);

	UFUNCTION(BlueprintCallable, Category="BangWrapper")
	FORTNITEUI_API void UnregisterTutorialNameID();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BangWrapper")
	EFortBangType BangType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BangWrapper", meta=(DisplayName="Tutorial Name"))
	FName TutorialNameID;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="BangWrapper")
	FORTNITEUI_API void OnBangStateChanged(bool bEnabled, int32 Count);

	UFUNCTION(BlueprintImplementableEvent, Category="BangWrapper")
	FORTNITEUI_API void OnStartCallout(FName TutorialObjectiveName, ETutorialType TutorialType);

	UFUNCTION(BlueprintImplementableEvent, Category="BangWrapper")
	FORTNITEUI_API void OnStopCallout();

	UFUNCTION(BlueprintImplementableEvent, Category="BangWrapper")
	FORTNITEUI_API void OnTutorialCalloutFinished();

	UPROPERTY(BlueprintReadOnly, Export, Category="BangWrapper", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UNamedSlot> ContentSlot;

};

