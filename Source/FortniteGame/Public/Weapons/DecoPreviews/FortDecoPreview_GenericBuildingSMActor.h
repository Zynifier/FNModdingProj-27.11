// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortDecoPreview.h"
#include "FortDecoPreview_GenericBuildingSMActor.generated.h"

class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortDecoPreview_GenericBuildingSMActor : public AFortDecoPreview
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PrimaryMeshComponent;

};

