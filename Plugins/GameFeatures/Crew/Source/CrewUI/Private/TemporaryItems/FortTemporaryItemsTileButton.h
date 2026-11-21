// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "FortTemporaryItemsTileButton.generated.h"

class UFortAccountItemDefinition;
class UFortCosmeticItemCard;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortTemporaryItemsTileButton : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetupRewardItem(const UFortAccountItemDefinition* ItemDef);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortTemporaryItemsTileButton", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> ItemCard;

};

