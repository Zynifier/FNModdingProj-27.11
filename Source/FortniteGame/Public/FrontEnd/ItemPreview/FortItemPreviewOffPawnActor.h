// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontEnd/ItemPreview/FortItemPreviewSingleAngleActor.h"
#include "FortItemPreviewOffPawnActor.generated.h"

class AActor;
class UChildActorComponent;
class UFortGliderSpawnComponent;
class UFortItemDefinition;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UTexture2D;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortItemPreviewOffPawnActor : public AFortItemPreviewSingleAngleActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UTexture2D> GetPreviewIcon() const;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOffPawnActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UChildActorComponent> PreviewActorComponent;

	UPROPERTY(VisibleAnywhere, Transient, Category="FortItemPreviewOffPawnActor")
	TObjectPtr<AActor> ChildPreviewActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOffPawnActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PreviewStaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewOffPawnActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> PreviewSkelMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortItemPreviewOffPawnActor", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<AActor> DefaultPreviewActorClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> ContentOnDemandItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="FortItemPreviewOffPawnActor", meta=(AllowPrivateAccess="TRUE"))
	bool bUseItemDefConfiguredLocation;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGliderSpawnComponent> GliderSpawnComponent;

};

