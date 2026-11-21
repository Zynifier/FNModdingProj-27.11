// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "DaySequenceBindingReference.generated.h"

class UObject;

USTRUCT()
struct FDaySequenceBindingReference
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TSoftObjectPtr<UObject> ExternalObjectPath;

	UPROPERTY()
	FString ObjectPath;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSoftClassPtr<UObject> ObjectClass_DEPRECATED;
#endif

};

USTRUCT()
struct FDaySequenceBindingReferenceArray
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FDaySequenceBindingReference> References;

};

USTRUCT()
struct FDaySequenceBindingReferences
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FGuid, FDaySequenceBindingReferenceArray> BindingIdToReferences;

	UPROPERTY()
	TSet<FGuid> AnimSequenceInstances;

};

