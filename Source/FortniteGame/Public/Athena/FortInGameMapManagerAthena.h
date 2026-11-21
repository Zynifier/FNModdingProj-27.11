// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "FortInGameMapManager.h"
#include "FortInGameMapManagerAthena.generated.h"

class AActor;
class AFortPlayerControllerZone;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortInGameMapManagerAthena : public AFortInGameMapManager
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleLocalPlayerStateSet();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DrawInFog")
	uint8 bDrawMapLocationsIfFogged : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DrawInFog")
	uint8 bDrawSpecialActorIconsIfFogged : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DrawInFog")
	uint8 bDrawSquadPinsIfFogged : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DrawInFog")
	uint8 bDrawMapIndicatorsIfFogged : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DrawInFog")
	uint8 bDrawEliminationsIfFogged : 1;

private:
	UFUNCTION()
	void HandlePlayerTeamIndexChanged();

	UFUNCTION()
	void OnAthenaPlayerControllerEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void OnBeginSkydivingFromBus(AFortPlayerControllerZone* FortPC);

	UFUNCTION()
	void OnEndSkydivingFromBus(AFortPlayerControllerZone* FortPC);

	UFUNCTION()
	void OnMapInfoEndPlay(AActor* InSource, EEndPlayReason::Type Reason);

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UMaterialInterface> MapMaskMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MapMaskMaterialMID;

};

