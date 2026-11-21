// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Math/MathFwd.h"
#include "FortPhysicsChainConstraint.h"
#include "FortPhysicsChainWeaponComponent.generated.h"

class UPrimitiveComponent;
class UStaticMesh;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPhysicsChainWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(CPP_Default_GCComponent="None", CPP_Default_AttachPosition, CPP_Default_AttachPointNormal))
	void EstablishChainConnectionPoint(UPrimitiveComponent* RootPoint, UPrimitiveComponent* GCComponent, const FVector& AttachPosition, const FVector& AttachPointNormal);

	UFUNCTION(BlueprintCallable)
	FVector GetChainConnectionPoint();

	UFUNCTION(BlueprintCallable)
	float GetChainLinkMeshLength();

	UFUNCTION(BlueprintCallable)
	bool GetCreateChainBool();

	UFUNCTION(BlueprintCallable)
	int32 GetMaxChainLength();

	UFUNCTION(BlueprintCallable)
	void SetCreateChainBool(bool bSetCreateChain);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint")
	UStaticMesh* ChainLinkMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint", meta=(ClampMin="1.0"))
	float LinkLengthModification;

	UPROPERTY(Replicated)
	bool bCreateChain;

	UPROPERTY(Replicated)
	FChainAttachPoint CurrentAttachPoint;

};

