// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortAmbientAudioController.generated.h"

class AFortPlayerController;
class UFortAmbientAudioController;
class UObject;
enum class EFortDayPhase : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortAmbientAudioController : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(DisplayName="GetAmbientAudioController", WorldContext="WorldContextObject"))
	static UFortAmbientAudioController* GetAmbientAudioControllerFromContext(UObject* WorldContextObject);

	UPROPERTY(EditDefaultsOnly, Category="Tag")
	FGameplayTag RequiredTagSubstr;

	UPROPERTY(BlueprintReadOnly, Category="FortAmbientAudioController")
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(Config)
	float PauseFadeTime;

private:
	UFUNCTION()
	void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

};

