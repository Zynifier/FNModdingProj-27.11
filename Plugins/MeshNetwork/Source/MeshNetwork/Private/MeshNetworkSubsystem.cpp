// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshNetworkSubsystem.h"

#ifndef FORTSTUB_SKIP_THUNK_PARAMS
#define FORTSTUB_SKIP_THUNK_PARAMS
static void FortStub_SkipThunkParams(FFrame& Stack, UFunction* Function)
{
	if (Function)
	{
		for (TFieldIterator<FProperty> It(Function); It && It->HasAnyPropertyFlags(CPF_Parm); ++It)
		{
			if (It->HasAnyPropertyFlags(CPF_ReturnParm))
			{
				continue;
			}
			void* Temp = FMemory::Malloc(It->GetSize(), It->GetMinAlignment());
			It->InitializeValue(Temp);
			Stack.StepCompiledIn(Temp, It->GetClass());
			It->DestroyValue(Temp);
			FMemory::Free(Temp);
		}
	}
	P_FINISH;
}
#endif

void UMeshNetworkSubsystem::DisableMeshReplication(AActor* Actor)
{
}

void UMeshNetworkSubsystem::EnableMeshReplication(AActor* Actor, TSubclassOf<UMeshNetworkComponent> MeshComponentClass)
{
}

bool UMeshNetworkSubsystem::GetConnectedToRoot() const
{
	return false;
}

EMeshNetworkNodeType UMeshNetworkSubsystem::GetGameServerNodeType() const
{
	return EMeshNetworkNodeType();
}

EMeshNetworkNodeType UMeshNetworkSubsystem::GetMeshNetworkNodeType() const
{
	return EMeshNetworkNodeType();
}

void UMeshNetworkSubsystem::GetMetaData(FMeshMetaDataStruct& MetaData)
{
}

DEFINE_FUNCTION(UMeshNetworkSubsystem::execGetMetaDataWithKey)
{
	FortStub_SkipThunkParams(Stack, UMeshNetworkSubsystem::StaticClass()->FindFunctionByName(TEXT("GetMetaDataWithKey")));
}
bool UMeshNetworkSubsystem::GetMetaDataWithKey(FName Key, FMeshMetaDataStruct& MetaData)
{
	return false;
}

void UMeshNetworkSubsystem::SetMetaData(const FMeshMetaDataStruct& MetaData)
{
}

DEFINE_FUNCTION(UMeshNetworkSubsystem::execSetMetaDataWithKey)
{
	FortStub_SkipThunkParams(Stack, UMeshNetworkSubsystem::StaticClass()->FindFunctionByName(TEXT("SetMetaDataWithKey")));
}
void UMeshNetworkSubsystem::SetMetaDataWithKey(FName Key, const FMeshMetaDataStruct& MetaData)
{
}
