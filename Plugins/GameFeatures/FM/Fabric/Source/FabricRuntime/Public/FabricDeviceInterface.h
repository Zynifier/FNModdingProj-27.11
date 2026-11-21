// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Sound/SoundEffectSource.h"
#include "FabricMeshProvider.h"
#include "FabricTextureProvider.h"
#include "FabricDeviceInterface.generated.h"

class UFabricFloatProviderBase;
class UFabricMeshModifierBase;
class UFabricMeshProviderBase;
class UFabricMetaSoundPatchWrapper;
class UFabricTextureModifierBase;
class UFabricTextureProviderBase;
class USoundSourceBus;

UINTERFACE()
class FABRICRUNTIME_API UFabricAudioGenerator : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricAudioGenerator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	FSourceEffectChainEntry GetAudioAnalyzer();

};

UINTERFACE()
class FABRICRUNTIME_API UFabricAudioModifier : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricAudioModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	TArray<FSourceEffectChainEntry> GetSourceEffectChainEntries();

};

UINTERFACE()
class FABRICRUNTIME_API UFabricAudioReceiver : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricAudioReceiver
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	USoundSourceBus* GetSoundSourceBus();

};

UINTERFACE()
class FABRICRUNTIME_API UFabricDevice : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricDevice
{
	GENERATED_BODY()

};

UINTERFACE()
class FABRICRUNTIME_API UFabricFloatGenerator : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricFloatGenerator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFabricFloatProviderBase* GetFloatProvider();

};

UINTERFACE()
class FABRICRUNTIME_API UFabricFloatReceiver : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricFloatReceiver
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void SetFloatProviders(const TArray<UFabricFloatProviderBase*>& FloatProvider);

};

UINTERFACE()
class FABRICRUNTIME_API UFabricMeshGenerator : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricMeshGenerator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFabricMeshProviderBase* GetMeshProvider();

};

UINTERFACE()
class FABRICRUNTIME_API UFabricMeshModifier : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricMeshModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFabricMeshModifierBase* GetMeshModifier() const;

	UFUNCTION(BlueprintNativeEvent)
	bool IsShowingMeshPreview() const;

	UFUNCTION(BlueprintNativeEvent)
	void OnMeshesChanged(const TArray<FFabricMeshInstanceReference>& InstanceMeshReferences, bool bInstancesChanged);

};

UINTERFACE()
class FABRICRUNTIME_API UFabricMeshReceiver : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricMeshReceiver
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnMeshInstanceReferencesChanged(const TArray<FFabricMeshInstanceReference>& MeshInstanceReferences, bool bMeshChanged, bool bInstancesChanged);

	UFUNCTION(BlueprintNativeEvent)
	void OnMeshInstancesChanged(const TArray<FTransform>& Meshes);

	UFUNCTION(BlueprintNativeEvent)
	void OnMeshReferenceChanged(const FFabricMeshProviderMeshReference& ReferenceMesh);

};

UINTERFACE()
class FABRICRUNTIME_API UFabricMetaSoundPatchOwner : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricMetaSoundPatchOwner
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFabricMetaSoundPatchWrapper* GetMetaSoundPatchWrapper();

};

UINTERFACE()
class FABRICRUNTIME_API UFabricTextureGenerator : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricTextureGenerator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFabricTextureProviderBase* GetTextureProvider();

};

UINTERFACE()
class FABRICRUNTIME_API UFabricTextureModifier : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricTextureModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFabricTextureModifierBase* GetTextureModifier();

	UFUNCTION(BlueprintNativeEvent)
	bool IsShowingTexturePreview() const;

};

UINTERFACE()
class FABRICRUNTIME_API UFabricTextureReceiver : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricTextureReceiver
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnTexturesChanged(const TArray<FFabricTextureProviderTexture>& Texture);

};

