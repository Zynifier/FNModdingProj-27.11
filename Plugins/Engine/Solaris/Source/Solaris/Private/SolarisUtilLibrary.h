// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SolarisUtilLibrary.generated.h"

class UObject;

UCLASS()
class USolarisUtilLibrary : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(CustomThunk)
	static void AddPropertyToSubobjectExclusionList(int64 InstancingGraph, int64 Property);
	DECLARE_FUNCTION(execAddPropertyToSubobjectExclusionList);

	UFUNCTION(CustomThunk)
	static int64 Addressof(int64 value);
	DECLARE_FUNCTION(execAddressof);

	UFUNCTION(CustomThunk)
	static void CallFinalFunctionWithContext();
	DECLARE_FUNCTION(execCallFinalFunctionWithContext);

	UFUNCTION(CustomThunk)
	static void CallFunction();
	DECLARE_FUNCTION(execCallFunction);

	UFUNCTION(CustomThunk)
	static int64 Dereference(int64 reference);
	DECLARE_FUNCTION(execDereference);

	UFUNCTION()
	static UObject* GetCurrentlyInstantiatedObject();

	/*FScriptDelegate*/
	UFUNCTION(CustomThunk)
	static void GetFunctionForInterfaceMethod(UObject* Object, FName MethodName);
	DECLARE_FUNCTION(execGetFunctionForInterfaceMethod);

	// int64 is a placeholder type for the actual value type

	UFUNCTION(CustomThunk)
	static int64 GetOptionValue(int64 option);
	DECLARE_FUNCTION(execGetOptionValue);

	UFUNCTION(CustomThunk)
	static bool HasInterface(UObject* Object, UClass* InterfaceClass);
	DECLARE_FUNCTION(execHasInterface);

	UFUNCTION(CustomThunk)
	static void InstanceFunction(UObject* Object, FName MethodName);
	DECLARE_FUNCTION(execInstanceFunction);

	UFUNCTION(CustomThunk)
	static void InstantiateObject(UClass* Class, int64 InstancingGraph);
	DECLARE_FUNCTION(execInstantiateObject);

	UFUNCTION(CustomThunk)
	static bool IsNonNullObject(UObject* Object);
	DECLARE_FUNCTION(execIsNonNullObject);

	UFUNCTION(CustomThunk)
	static bool IsOptionSet(int64 option);
	DECLARE_FUNCTION(execIsOptionSet);

	UFUNCTION(CustomThunk)
	static bool MakeOptionFromValue(UObject* property, int64 value);
	DECLARE_FUNCTION(execMakeOptionFromValue);

	// FProperty hidden in UObject pointer

	UFUNCTION(CustomThunk)
	static int64 MakeUnsetOption();
	DECLARE_FUNCTION(execMakeUnsetOption);

	UFUNCTION(CustomThunk)
	static bool ObjectHasNoFlags(UObject* Object, int32 Flags);
	DECLARE_FUNCTION(execObjectHasNoFlags);

	UFUNCTION(CustomThunk)
	static bool ReferenceIsValid(int64 reference);
	DECLARE_FUNCTION(execReferenceIsValid);

	// int64 is a placeholder type for the actual value type

	UFUNCTION(CustomThunk)
	static int64 ReplaceOptionValue(int64 ResultProperty, int64 Option, int64 Value);
	DECLARE_FUNCTION(execReplaceOptionValue);

};

