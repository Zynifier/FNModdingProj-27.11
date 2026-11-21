// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseDigest.generated.h"

UENUM()
enum class EVerseDigestVariant : uint8
{
	PublicOnly = 0,
	PublicAndEpicInternal = 1,
};

/*
 * Container object for a Verse digest source snippet
 */
UCLASS()
class UVerseDigest : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint8> DigestCode;

	UPROPERTY()
	TArray<uint8> ManifestCode;

	// The project this digest belongs to
// (for determining the local file path of the digest)

	UPROPERTY()
	FString ProjectName;

	UPROPERTY()
	EVerseDigestVariant Variant;

	// Store if the -CookAllVerseInternalDigests was passed in during cook of this digest

	UPROPERTY()
	bool bCookAllVerseInternalDigests;

};

