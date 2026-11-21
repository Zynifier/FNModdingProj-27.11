// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CrashReporterBlueprintLibrary.generated.h"

UCLASS()
class UCrashReporterBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void LogException(const FString& Message);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void LogMessage(const FString& Message);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void SetBooleanKey(const FString& Key, bool Value);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void SetFloatKey(const FString& Key, float Value);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void SetIntegerKey(const FString& Key, int32 Value);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void SetStringKey(const FString& Key, const FString& Value);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void SetUserEmail(const FString& Email);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void SetUserIdentifier(const FString& ID);

	UFUNCTION(BlueprintCallable, Category="CrashReporter")
	static void SetUserName(const FString& Name);

};

