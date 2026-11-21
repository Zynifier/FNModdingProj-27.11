// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortPlayspaceReplicatedState.generated.h"

class UActorComponent_ReplicatedParamHelper;

UCLASS(MinimalAPI, BlueprintType)
class AFortPlayspaceReplicatedState : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UActorComponent_ReplicatedParamHelper* GetReplicatedParamHelper() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerInOwningPlayspace(int32 PlayerIndex = 0) const;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UActorComponent_ReplicatedParamHelper> CachedRepParamHelper;

};

