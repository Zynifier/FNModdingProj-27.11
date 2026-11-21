// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Collections/AthenaCollectionScreenBase.h"
#include "AthenaCollectionScreenMapBase.generated.h"

class UAthenaFullScreenMapBase;
class UAthenaMapCollectionIcon;

UCLASS(Abstract, MinimalAPI)
class UAthenaCollectionScreenMapBase : public UAthenaCollectionScreenBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaFullScreenMapBase> MapWidget;

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaCollectionScreenMapBase")
	TSubclassOf<UAthenaMapCollectionIcon> CollectionIconType;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FGameplayTag, UAthenaMapCollectionIcon*> MapCollectionIcons;

};

