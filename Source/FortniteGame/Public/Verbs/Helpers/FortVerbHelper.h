// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVerbHelper.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FFortVerb_ObjectWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortVerb_ObjectWrapper", meta=(AllowPrivateAccess))
	TWeakObjectPtr<UObject> UObjectPtr;

};

