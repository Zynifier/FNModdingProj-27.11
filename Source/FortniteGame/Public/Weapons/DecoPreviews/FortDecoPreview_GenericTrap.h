// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/DecoPreviews/FortDecoPreview_GenericBuildingSMActor.h"
#include "FortDecoPreview_GenericTrap.generated.h"

class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortDecoPreview_GenericTrap : public AFortDecoPreview_GenericBuildingSMActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TrapRangeMeshComponent;

};

