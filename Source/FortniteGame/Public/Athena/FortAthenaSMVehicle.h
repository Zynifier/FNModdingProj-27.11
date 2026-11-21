// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaVehicle.h"
#include "FortAthenaSMVehicle.generated.h"

class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaSMVehicle : public AFortAthenaVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Mesh,Rendering,Physics,Components|StaticMesh"))
	TObjectPtr<UStaticMeshComponent> Mesh;

};

