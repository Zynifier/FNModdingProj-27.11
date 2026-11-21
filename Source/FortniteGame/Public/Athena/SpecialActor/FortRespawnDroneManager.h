// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortRespawnDroneManager.generated.h"

class ACameraActor;
class AFortPlayerControllerAthena;
class AFortPlayerPawnAthena;
class AFortRespawnDroneManager;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRespawnDroneManagerFinished, AFortRespawnDroneManager*, DroneManager);

UCLASS(BlueprintType, Blueprintable)
class FORTNITEGAME_API AFortRespawnDroneManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	ACameraActor* GetCamera() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="BeginRespawnSequence"))
	void BeginRespawnSequence_BP(AFortPlayerPawnAthena* PlayerPawn, AFortPlayerControllerAthena* PlayerController, const FVector& RespawnLocation, const float RespawnTime);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndRespawnSequence();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRespawnDroneManager")
	float PostFinishLifeSpan;

};

