// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FortBodyPartOverridePreviewActor.generated.h"

class AFortPlayerController;
class AFortPlayerPawn;
class UAthenaCharacterPartItemDefinition;

UCLASS(Abstract, BlueprintType)
class AFortBodyPartOverridePreviewActor : public AActor, public IFortUICameraFrameTargetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Cosmetics")
	void ApplyMyCosmeticItemToHero(AFortPlayerPawn* PawnToModify, AFortPlayerController* FortPC);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetics")
	void OnPreviewCosmeticItem();

	UPROPERTY()
	TObjectPtr<UAthenaCharacterPartItemDefinition> MyCosmeticItem;

	UPROPERTY()
	FFortOnCameraFrameTargetSettingsChangedDelegate OnSettingsChangedDelegate;

};

