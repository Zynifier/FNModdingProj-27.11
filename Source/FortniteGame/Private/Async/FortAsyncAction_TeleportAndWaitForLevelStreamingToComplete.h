// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Math/MathFwd.h"
#include "FortAsyncAction_TeleportAndWaitForLevelStreamingToComplete.generated.h"

class AActor;
class AFortPlayerPawn;
class UFortAsyncAction_TeleportAndWaitForLevelStreaming;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTeleportAndWaitForLevelStreamingDelegate);

UCLASS()
class UFortAsyncAction_TeleportAndWaitForLevelStreaming : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_TeleportAndWaitForLevelStreaming* CreateTeleportAndWaitForLevelStreaming(AFortPlayerPawn* InPlayerPawn, const FVector& InTeleportLocation, const FRotator& InTeleportRotation, const bool bIgnoreCollision, const bool bIgnoreSupplementalKillVolumeSweep = false);

	UPROPERTY(BlueprintAssignable)
	FTeleportAndWaitForLevelStreamingDelegate OnComplete;

protected:
	UFUNCTION()
	void OnLevelStreamingComplete();

	UFUNCTION()
	void OnPawnEndPlay(AActor* Actor, EEndPlayReason::Type Reason);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(Transient)
	FVector TeleportLocation;

	UPROPERTY(Transient)
	FRotator TeleportRotation;

	UPROPERTY(Transient)
	bool bIgnoreCollision;

	UPROPERTY(Transient)
	bool bIgnoreSupplementalKillVolumeSweep;

};

