// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorSandMound.generated.h"

class UMaterialInstanceDynamic;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorSandMound : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="BuildingGameplayActorSandMound")
	float MeshRotationInterpSpeed;

	UPROPERTY(Transient)
	FRotator TargetMeshRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingGameplayActorSandMound", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> MoundMesh;

	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorSandMound")
	TObjectPtr<UMaterialInstanceDynamic> MoundMID;

};

