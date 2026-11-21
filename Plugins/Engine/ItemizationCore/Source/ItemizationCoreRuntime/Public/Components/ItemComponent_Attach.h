// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemComponentBase.h"
#include "ItemComponent_Attach.generated.h"

class UAnimInstance;
class UItemAttachmentDefinition;
class USkeletalMesh;

// User facing options for which states apply e.g. to a mesh

UENUM()
enum class EItemStateFilter : int32
{
	Always = 0,
	/// applies in all states

	Active = 1,
	/// applies when the item is equipped

	Inactive = 2,
};

UCLASS(DefaultToInstanced, EditInlineNew)
class ITEMIZATIONCORERUNTIME_API UItemAttachmentDefinition : public UObject
{
	GENERATED_BODY()

public:
	/** When should this item be visible? */
	UPROPERTY(EditDefaultsOnly, Category="Item Attachment")
	EItemStateFilter ItemVisibility;

	/** Skeletal mesh to display when this item is visible */
	UPROPERTY(EditDefaultsOnly, Category="Item Attachment")
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	/** Socket to attach the mesh to (on the owner) */
	UPROPERTY(EditDefaultsOnly, Category="Item Attachment", meta=(EditCondition="SkeletalMesh != nullptr", EditConditionHides))
	FName AttachToSocketName;

	/** Animation layer overlay to apply when this item is visible. This will override specific parts of the main pawn animation tree. This can be null if the item doesn't need custom animation logic. */
	UPROPERTY(EditDefaultsOnly, Category="Item Attachment")
	TSubclassOf<UAnimInstance> AnimLayerOverlayClass;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemComponent_Attach : public UItemComponentBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Attach Component")
	TArray<UItemAttachmentDefinition*> MeshAttachments;

};

