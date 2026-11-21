// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemAttribute.h"
#include "ItemComponentBase.h"
#include "ItemComponent_Stackable.generated.h"

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_MaxStackSize : public UItemAttribute_Int
{
	GENERATED_BODY()

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_StackSize : public UItemAttribute_Int
{
	GENERATED_BODY()

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemComponent_Stackable : public UItemComponentBase
{
	GENERATED_BODY()

private:
	//All items must be able to have one of themselves by default.

	UPROPERTY(EditDefaultsOnly, Category="Stackable Component", meta=(ClampMin="1"))
	int64 MaxStackSize;

	UPROPERTY(EditDefaultsOnly, Category="Stackable Component")
	bool AllowMultipleStacks;

	UPROPERTY(EditDefaultsOnly, Category="Stackable Component")
	bool DestroyEmptyStacks;

};

