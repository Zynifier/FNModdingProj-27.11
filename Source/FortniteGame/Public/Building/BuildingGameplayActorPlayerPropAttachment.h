// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorPlayerPropAttachment.generated.h"

class AActor;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorPlayerPropAttachment : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="PlayerPropAttachment")
	void AttachProp(AActor* PropActorToAttach);

	UFUNCTION(BlueprintPure, Category="PlayerPropAttachment")
	void CalcWorldSpaceBounds(AActor* PropActor, FVector& Origin, FVector& Extent) const;

	UFUNCTION(BlueprintCallable, Category="PlayerPropAttachment")
	void InitProp(AActor* PropActorToAttach);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="PlayerPropAttachment")
	void LogState(const FString& CallingContext) const;

	UPROPERTY(EditDefaultsOnly, Category="BuildingGameplayActorPlayerPropAttachment")
	bool bClientAttachmentErrorCorrectionEnabled;

	UPROPERTY(EditDefaultsOnly, Category="BuildingGameplayActorPlayerPropAttachment")
	bool bUseTransformedCalcBounds;

protected:
	UFUNCTION(BlueprintPure, Category="PlayerPropAttachment")
	bool DoesMeshComponentHaveVisibleMaterial(const UStaticMeshComponent* StaticMeshComponent) const;

};

