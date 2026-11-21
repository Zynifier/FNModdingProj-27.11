// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintCompilerExtension.h"
#include "MeshNetworkBlueprintCompilerExtension.generated.h"

UCLASS(Abstract)
class UMeshNetworkBlueprintCompilerExtension : public UBlueprintCompilerExtension
{
	GENERATED_BODY()

public:
	UMeshNetworkBlueprintCompilerExtension(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

