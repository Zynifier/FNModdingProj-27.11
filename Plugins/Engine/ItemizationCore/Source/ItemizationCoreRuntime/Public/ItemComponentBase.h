// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemComponentBase.generated.h"

/**
 * Abstract base class for a component of an item definition/variant/part. Native usage example; ItemData.GetComponent<UItemComponent_Core>()->GetItemType().
 * If bUseComponentDefaultsIfNotPresent is true for a component, calling UItemDefinitionBase::GetItemComponentByClass() will return the CDO of the provided component class even if the item definition does not have it.
 */
UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class ITEMIZATIONCORERUNTIME_API UItemComponentBase : public UPrimaryDataAsset
{
	GENERATED_BODY()

};

