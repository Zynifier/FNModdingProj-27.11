// Copyright Epic Games, Inc. All Rights Reserved.

#include "Valkyrie/FortExposedAssetProviderLibrary.h"

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

void UFortExposedAssetProviderLibrary::AddVersion(FFortExposedAssetProviderVersion& VersionRef, const int32 Version)
{
}

DEFINE_FUNCTION(UFortExposedAssetProviderLibrary::execCollectClassSparseDataAssetPropertyReferences)
{
	FortStub_SkipThunkParams(Stack, UFortExposedAssetProviderLibrary::StaticClass()->FindFunctionByName(TEXT("CollectClassSparseDataAssetPropertyReferences")));
}
void UFortExposedAssetProviderLibrary::CollectClassSparseDataAssetPropertyReferences(FFortExposedAssetReferenceCollector& CollectorRef, UObject* Object, const int32& Property)
{
}

DEFINE_FUNCTION(UFortExposedAssetProviderLibrary::execCollectClassSparseDataClassPropertyReferences)
{
	FortStub_SkipThunkParams(Stack, UFortExposedAssetProviderLibrary::StaticClass()->FindFunctionByName(TEXT("CollectClassSparseDataClassPropertyReferences")));
}
void UFortExposedAssetProviderLibrary::CollectClassSparseDataClassPropertyReferences(FFortExposedClassReferenceCollector& CollectorRef, UObject* Object, const int32& Property)
{
}

void UFortExposedAssetProviderLibrary::CollectIndirectAssetReference(FFortExposedAssetReferenceCollector& CollectorRef, const TSoftObjectPtr<UObject>& Value)
{
}

void UFortExposedAssetProviderLibrary::CollectIndirectClassReference(FFortExposedClassReferenceCollector& CollectorRef, const TSoftClassPtr<UObject>& Value)
{
}

DEFINE_FUNCTION(UFortExposedAssetProviderLibrary::execCollectObjectPropertyAssetReferences)
{
	FortStub_SkipThunkParams(Stack, UFortExposedAssetProviderLibrary::StaticClass()->FindFunctionByName(TEXT("CollectObjectPropertyAssetReferences")));
}
void UFortExposedAssetProviderLibrary::CollectObjectPropertyAssetReferences(FFortExposedAssetReferenceCollector& CollectorRef, UObject* Object, const int32& Property)
{
}

DEFINE_FUNCTION(UFortExposedAssetProviderLibrary::execCollectObjectPropertyClassReferences)
{
	FortStub_SkipThunkParams(Stack, UFortExposedAssetProviderLibrary::StaticClass()->FindFunctionByName(TEXT("CollectObjectPropertyClassReferences")));
}
void UFortExposedAssetProviderLibrary::CollectObjectPropertyClassReferences(FFortExposedClassReferenceCollector& CollectorRef, UObject* Object, const int32& Property)
{
}
