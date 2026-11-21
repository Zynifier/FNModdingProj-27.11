// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "ItemAttributeValueTypes.generated.h"

class AInventoryCollection;

/*
 * Objects that contain some attribute's value as a result of a query. Used by Verse.
 */
UCLASS(Transient)
class ITEMIZATIONCORERUNTIME_API UItemAttributeValueBase : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGuid QueriedItemEntryID;

	UPROPERTY()
	TWeakObjectPtr<AInventoryCollection> QueriedInventoryCollection;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttributeValue_Bool : public UItemAttributeValueBase
{
	GENERATED_BODY()

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttributeValue_Decimal : public UItemAttributeValueBase
{
	GENERATED_BODY()

};

//These are here just to be pretty for now but in the future (like with string) native may want to intercept values going into/coming out of these objects (for cabin mode for example).

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttributeValue_Int : public UItemAttributeValueBase
{
	GENERATED_BODY()

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttributeValue_String : public UItemAttributeValueBase
{
	GENERATED_BODY()

};

