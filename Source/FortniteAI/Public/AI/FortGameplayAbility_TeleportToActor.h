// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_TeleportToActor.generated.h"

class AFortPawn;
class UEnvQuery;

UCLASS()
class UFortGameplayAbility_TeleportToActor : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Ability", meta=(DisplayName="On Post Teleported Pawn", ScriptName="OnPostTeleportedPawn"))
	void PostTeleportedPawn(AFortPawn* TeleportedPawn);

	UFUNCTION(BlueprintImplementableEvent, Category="Ability", meta=(DisplayName="On Pre Teleport Pawn", ScriptName="OnPreTeleportPawn"))
	void PreTeleportPawn(AFortPawn* TeleportedPawn);

private:
	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true"))
	bool bCheckPlayerLOSWhenTeleporting;

	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true", ClampMin="0.0", EditCondition="bCheckPlayerLOS == true", EditConditionHides, UIMin="0.0"))
	float MaxDistanceToConsiderLOS;

	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true", ClampMax="360.0", ClampMin="0.0", EditCondition="bCheckPlayerLOS == true", EditConditionHides, UIMax="360.0", UIMin="0.0"))
	float PlayerFOV;

	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	float TeleportDelay;

	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true", ClampMin="0", UIMin="0"))
	int32 TeleportRetries;

	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true", ClampMin="0.0", UIMin="0.0"))
	float RetryDelay;

	UPROPERTY(EditAnywhere, Category="Teleport", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UEnvQuery> FindTeleportSpotEQSQuery;

};

