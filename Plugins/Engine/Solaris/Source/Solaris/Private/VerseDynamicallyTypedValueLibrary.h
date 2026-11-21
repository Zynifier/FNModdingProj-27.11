// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseDynamicallyTypedValueLibrary.generated.h"

class UObject;

UCLASS()
class UVerseDynamicallyTypedValueLibrary : public UObject
{
	GENERATED_BODY()

public:
	/*UE::FDynamicallyTypedValue*/
	UFUNCTION(CustomThunk)
	static void ConvertFromDynamicallyTypedValue(int32 RuntimeType, int32 Value);
	DECLARE_FUNCTION(execConvertFromDynamicallyTypedValue);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void ConvertToDynamicallyTypedValue(int32 RuntimeType, int32 Value);
	DECLARE_FUNCTION(execConvertToDynamicallyTypedValue);

	/*UE::FDynamicallyTypedValue*/
	UFUNCTION(CustomThunk)
	static void Equal(int32 Left, int32 Right);
	DECLARE_FUNCTION(execEqual);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeArray(int32 ElementType);
	DECLARE_FUNCTION(execMakeRuntimeTypeArray);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeChar32();
	DECLARE_FUNCTION(execMakeRuntimeTypeChar32);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeChar8();
	DECLARE_FUNCTION(execMakeRuntimeTypeChar8);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeClass();
	DECLARE_FUNCTION(execMakeRuntimeTypeClass);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeDynamic();
	DECLARE_FUNCTION(execMakeRuntimeTypeDynamic);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeEnum(FName Name);
	DECLARE_FUNCTION(execMakeRuntimeTypeEnum);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeFloat();
	DECLARE_FUNCTION(execMakeRuntimeTypeFloat);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeFunction();
	DECLARE_FUNCTION(execMakeRuntimeTypeFunction);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeInt64();
	DECLARE_FUNCTION(execMakeRuntimeTypeInt64);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeLogic();
	DECLARE_FUNCTION(execMakeRuntimeTypeLogic);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeMap(int32 KeyType, int32 ValueType);
	DECLARE_FUNCTION(execMakeRuntimeTypeMap);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeObject();
	DECLARE_FUNCTION(execMakeRuntimeTypeObject);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeOption(int32 ValueType);
	DECLARE_FUNCTION(execMakeRuntimeTypeOption);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeString();
	DECLARE_FUNCTION(execMakeRuntimeTypeString);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeStruct(UObject* Struct);
	DECLARE_FUNCTION(execMakeRuntimeTypeStruct);

	/*UE::Verse::FRuntimeType* */
	UFUNCTION(CustomThunk)
	static void MakeRuntimeTypeTuple(TArray<int32> ValueType);
	DECLARE_FUNCTION(execMakeRuntimeTypeTuple);

	/*UE::FDynamicallyTypedValue*/
	UFUNCTION(CustomThunk)
	static void NotEqual(int32 Left, int32 Right);
	DECLARE_FUNCTION(execNotEqual);

};

