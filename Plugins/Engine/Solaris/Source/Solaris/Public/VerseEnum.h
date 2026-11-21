// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseEnum.generated.h"

class UEnumCookedMetaData;

UENUM()
enum class EVerseEnumFlags : uint32
{
	None = 0,
	NativeBound = 1,
};

UCLASS()
class SOLARIS_API UVerseEnum : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EVerseEnumFlags VerseEnumFlags;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UEnumCookedMetaData> CachedCookedMetaDataPtr;
#endif

};

