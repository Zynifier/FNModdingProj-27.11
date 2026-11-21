// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortDecoPreview.h"
#include "FortDecoPreview_StaticMesh.generated.h"

class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortDecoPreview_StaticMesh : public AFortDecoPreview
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Export, Category="FortDecoPreview_StaticMesh", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PrimaryMeshComponent;

};

