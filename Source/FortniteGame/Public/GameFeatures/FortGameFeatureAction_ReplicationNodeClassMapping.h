// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Online/FortCustomRepGraphNode.h"
#include "FortGameFeatureAction_ReplicationNodeClassMapping.generated.h"

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="CustomReplicationNodeClassMapping"))
class UFortGameFeatureAction_ReplicationNodeClassMapping : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Networking")
	TArray<FFortCustomRepNodeClassMapping> CustomRepNodeClassMappings;

};

