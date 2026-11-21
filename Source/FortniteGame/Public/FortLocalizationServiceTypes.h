// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLocalizationServiceTypes.generated.h"

USTRUCT(BlueprintType)
struct FLocalizedStringPair
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="LocalizedStringPair")
	FString Locale;

	UPROPERTY(BlueprintReadOnly, Category="LocalizedStringPair")
	FString TextLiteral;

};

USTRUCT()
struct FReplicatedTranslatedStrings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	FString Name;

	UPROPERTY()
	TArray<FLocalizedStringPair> Translations;

};

USTRUCT()
struct FReplicatedLocalizedDocument
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	FString SourceLang;

	UPROPERTY()
	TArray<FReplicatedTranslatedStrings> Strings;

};

USTRUCT()
struct FReplicatedTranslatedString
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Locale;

	UPROPERTY()
	FString Literal;

};

