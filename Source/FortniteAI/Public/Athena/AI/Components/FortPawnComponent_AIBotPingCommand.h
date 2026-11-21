// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/Components/FortPawnComponent_PingCommand.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "FortPawnComponent_AIBotPingCommand.generated.h"

class AAIController;
class AFortPawn;
class AFortPlayerPawn;
enum class EUnconvertReason : uint8;
enum class PingCommandType : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEAI_API UFortPawnComponent_AIBotPingCommand : public UFortPawnComponent_PingCommand
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleOnNPCConvertEvent(AFortPawn* InstigatorPawn, AFortPawn* ConvertedPawn);

	UFUNCTION()
	void HandleOnNPCUnconvertEvent(AFortPawn* UnconvertedFortPawn, EUnconvertReason UnconvertReason);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAIPingCommand(AFortPlayerPawn* PlayerPawn, PingCommandType CommandType);

	UFUNCTION()
	void OnServerMarkerAdded(const FFortWorldMarkerData& MarkerData);

	UFUNCTION()
	void OnServerMarkerRemoved(FMarkerID MarkerID);

private:
	UPROPERTY(Transient)
	TObjectPtr<AAIController> CachedOwnerController;

};

