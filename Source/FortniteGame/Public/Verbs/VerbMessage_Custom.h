// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Verbs/VerbMessage.h"
#include "VerbMessage_Custom.generated.h"

class UObject;

USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/FortniteGame.CustomVerbMessageLibrary.MakeCustomVerbMessage"))
struct FVerbMessage_Custom : public FVerbMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="VerbMessage_Custom", meta=(Categories="CustomVerb"))
	FGameplayTag Verb;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="VerbMessage_Custom")
	int32 Amount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="VerbMessage_Custom")
	TMap<FName, FSubjectTagsPair> Subjects;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="VerbMessage_Custom")
	TMap<FName, float> Values;

};

UCLASS(MinimalAPI, meta=(ScriptName="CustomVerbMessageLibrary"))
class UCustomVerbMessageLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Custom Verb")
	static void AddTagsForSubject(UPARAM(ref) FVerbMessage_Custom& CustomVerb, FName SubjectName, const FGameplayTagContainer& SubjectTags, FVerbMessage_Custom& Result);

	UFUNCTION(BlueprintCallable, Category="Custom Verb")
	static void AddTagsFromSubject(UPARAM(ref) FVerbMessage_Custom& CustomVerb, FName SubjectName, UObject* SubjectObject, FVerbMessage_Custom& Result);

	UFUNCTION(BlueprintCallable, Category="Custom Verb")
	static void AddValue(UPARAM(ref) FVerbMessage_Custom& CustomVerb, FName ValueName, float Value, FVerbMessage_Custom& Result);

	UFUNCTION(BlueprintCallable, Category="Custom Verb", meta=(DefaultToSelf="Context"))
	static void BroadcastCustomVerbMessage(const FVerbMessage_Custom& CustomVerb);

	UFUNCTION(BlueprintPure, Category="Custom Verb")
	static FVerbMessage_Custom MakeCustomVerbMessage(UObject* const& Author, FGameplayTag VerbName, int32 Amount = 1);

	UFUNCTION(BlueprintCallable, Category="Custom Verb")
	static void OverrideContextLocation(UPARAM(ref) FVerbMessage_Custom& CustomVerb, const FVector& ContextLocation, FVerbMessage_Custom& Result);

};

