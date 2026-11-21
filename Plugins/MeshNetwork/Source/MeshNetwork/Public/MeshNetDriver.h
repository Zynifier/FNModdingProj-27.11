// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IpNetDriver.h"
#include "MeshNetDriver.generated.h"

class AActor;

UCLASS()
class MESHNETWORK_API UMeshNetDriver : public UIpNetDriver
{
	GENERATED_BODY()

public:
	UMeshNetDriver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY()
	TArray<TObjectPtr<AActor>> ClientDormantDynamicActors;

};

