// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortPhysicsReplicatedTargetGhost.generated.h"

class UMaterialInterface;
class USkeletalMeshComponent;
class UStaticMeshComponent;

UCLASS(Config=Game, BlueprintType, Blueprintable)
class AFortPhysicsReplicatedTargetGhost : public AActor
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Physics Ghost|Preview")
	TSoftObjectPtr<UMaterialInterface> PreviewMaterial;
#endif

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Physics Ghost", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Physics Ghost", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMesh;

};

