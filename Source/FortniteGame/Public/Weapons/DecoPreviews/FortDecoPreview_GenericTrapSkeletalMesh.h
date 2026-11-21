// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/DecoPreviews/FortDecoPreview_GenericTrap.h"
#include "FortDecoPreview_GenericTrapSkeletalMesh.generated.h"

class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortDecoPreview_GenericTrapSkeletalMesh : public AFortDecoPreview_GenericTrap
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkelMeshComponent;

};

