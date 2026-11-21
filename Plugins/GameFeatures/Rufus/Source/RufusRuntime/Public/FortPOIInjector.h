// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "FortPOIInjector.generated.h"

class AActor;
class AFortPlayerController;
class UDataTable;
class UFortControllerComponent;
class UMaterialInterface;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Actor", "Input", "LOD"))
class AFortPOIInjector : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void FortPlayerControllerEndingPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void HandleActorSpawned(AActor* SpawnedActor);

	UFUNCTION()
	void HandleControllerComponentAttached(AFortPlayerController* FortPlayerController, UFortControllerComponent* ControllerComponent);

private:
	UPROPERTY(EditAnywhere, Category="FortPOIInjector")
	TObjectPtr<UDataTable> ChallengeMapPoiDataToAdd;

	UPROPERTY(EditAnywhere, Category="FortPOIInjector")
	bool bStartPOIsDiscovered;

	UPROPERTY(EditAnywhere, Category="FortPOIInjector", meta=(EditCondition="bStartPOIsDiscovered", EditConditionHides, HideInDetailPanel))
	bool bNullifyPOIQuestReferences;

	UPROPERTY(EditAnywhere, Category="FortPOIInjector")
	bool bWaitForCanRecordPlayerVisits;

	UPROPERTY(EditAnywhere, Category="FortPOIInjector")
	TObjectPtr<UMaterialInterface> StencilMaterialToUse;

};

