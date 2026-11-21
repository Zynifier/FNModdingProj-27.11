// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricMetasoundManagerComponent.h"
#include "FabricMetasoundPatchWrapper.h"
#include "FabricMetasoundSplitterPatchWrapper.generated.h"

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundSplitterPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<FName, FFabricMetaSoundNodeInfo> SplitterNodes;

};

