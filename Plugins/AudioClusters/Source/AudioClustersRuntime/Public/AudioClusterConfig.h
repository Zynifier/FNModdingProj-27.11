// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AudioClusterConfig.generated.h"

class UAudioClusterBehavior;

UCLASS(BlueprintType)
class AUDIOCLUSTERSRUNTIME_API UAudioClusterConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Behavior")
	TObjectPtr<UAudioClusterBehavior> Behavior;

};

