// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FortCustomCharmTypeEnum.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortCharmPreviewActor.generated.h"

class AFortPlayerController;
class AFortPlayerPawn;
class UAthenaCharmItemDefinition;

UCLASS(Abstract, BlueprintType)
class AFortCharmPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Cosmetics")
	void ApplyMyCosmeticItemToHero(AFortPlayerPawn* PawnToModify, AFortPlayerController* FortPC);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetics")
	void OnPreviewCosmeticItem();

	UFUNCTION(BlueprintCallable, Category="Cosmetics")
	void SetActiveCharmSlot(int32 CharmSlotIn);

	UPROPERTY()
	TObjectPtr<UAthenaCharmItemDefinition> MyCosmeticItem;

	UPROPERTY()
	TEnumAsByte<EFortCustomCharmType::Type> CharmSlot;

	UPROPERTY()
	FFortOnCameraFrameTargetSettingsChangedDelegate OnSettingsChangedDelegate;

};

