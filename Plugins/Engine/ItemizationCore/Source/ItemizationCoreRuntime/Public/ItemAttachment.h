// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory.h"
#include "ItemAttachment.generated.h"

class UItemAttachmentDefinition;
class USkeletalMeshComponent;

/** This class is the in-game representation of an item attachment component (ItemComponent_Attach),
	and is intended to represent all in-game feedback such as meshes, VFX, sound effects, and so on.

	This class exists on both client & server and can launch effects, spawn meshes, etc on either
	or both (the current default) but is not intended to manage synchronizing them afterwards. */
UCLASS(MinimalAPI)
class AItemAttachment : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_AttachmentDataChanged();

	UFUNCTION()
	void OnRep_ItemStateChanged();

	/** The skeletal mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Visuals", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh;

	UPROPERTY(ReplicatedUsing=OnRep_AttachmentDataChanged, Export, meta=(EditInline="true"))
	TObjectPtr<UItemAttachmentDefinition> AttachmentData;

	UPROPERTY(ReplicatedUsing=OnRep_ItemStateChanged)
	EItemState ItemState;

};

